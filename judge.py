'''
judge.py
This module is used to judge the correctness of solutions.

You should fill the `inputs` and `expected_outputs` variable in `data.py`
in the same directory with this file.
'''
import subprocess
import os
from rich import inspect, print
from rich.console import Console
from rich.table import Table
from rich.style import Style
from rich.panel import Panel
from rich import box
from concurrent.futures import ThreadPoolExecutor, as_completed
import time

from dataclasses import dataclass, field

try:
    from data import input_data, expected_outputs, TARGET
except ImportError:
    print("[red]Error: data.py not found or incomplete![/red]")
    exit(1)

def handle_newline(s: str) -> str:
    s = s.replace("\n", "[dim]\\n[/dim]\n")
    s = s[:-1] if s.endswith("\n") else s
    return s


console = Console(log_time_format="[%X.%f]")

if len(input_data) != len(expected_outputs):
    console.log(
        "[red]Error: The number of inputs and expected outputs do not match![/red]"
    )
    exit(1)


def compile_c_code(source_file, output_file):
    compile_command = ["gcc", source_file, "-o", output_file]
    result = subprocess.run(compile_command, capture_output=True, text=True)
    if result.returncode != 0:
        console.log(f"[red]Compilation failed:[/red]\n{result.stderr}")
        exit(1)


def readable_perf_time(ns: int) -> str:
    if ns < 1_000:
        return f"{ns} ns"
    elif ns < 1_000_000:
        return f"{ns / 1_000:.3f} µs"
    elif ns < 1_000_000_000:
        return f"{ns / 1_000_000:.3f} ms"
    else:
        return f"{ns / 1_000_000_000:.3f} s"


dirname = os.path.dirname(TARGET)
basename = os.path.basename(TARGET)
basename_no_ext = os.path.splitext(basename)[0]
output_file = os.path.join(dirname, basename_no_ext)
t0 = time.perf_counter_ns()
compile_c_code(TARGET, output_file)
t1 = time.perf_counter_ns()

console.log(
    f"[green]Compilation succeeded in {readable_perf_time(t1 - t0)}![/green]")

console.log(
    f"You can run the executable file at: `[link={output_file} blue bold]{output_file}[/]`"
)

console.log(f"Loaded {len(input_data)} test cases.")

results: list[subprocess.CompletedProcess] = []
execution_times = []  # 添加一个列表来存储每个测试用例的执行时间

for idx, inp in enumerate(input_data):
    console.log(f"[blue]Running test case {idx + 1}...[/blue]")
    # Ensure input is a string
    input_str = str(inp)
    
    # 添加子进程执行计时
    start_time = time.perf_counter_ns()
    result: subprocess.CompletedProcess[str] = subprocess.run(
        [output_file], input=input_str, capture_output=True, text=True, timeout=None)
    end_time = time.perf_counter_ns()
    execution_time = end_time - start_time
    execution_times.append(execution_time)
    
    results.append(result)
    if result.returncode != 0:
        console.log(
            f"[red]Test case {idx + 1} failed due to execution error.[/red]")
        continue

    expected_output = expected_outputs[idx]
    if result.stdout == expected_output:
        console.log(f"[green]Test case {idx + 1} passed! (Took {readable_perf_time(execution_time)})[/green]")
    else:
        console.log(f"[red]Test case {idx + 1} failed! (Took {readable_perf_time(execution_time)})[/red]")
        console.log(f"[yellow]Input:[/yellow]\n{handle_newline(str(inp))}")
        console.log(
            f"[yellow]Expected Output:[/yellow]\n{handle_newline(expected_output)}")
        console.log(
            f"[yellow]Actual Output:[/yellow]\n{handle_newline(result.stdout)}")

# Summary Table
results_table = Table(expand=True,
                      box=box.SIMPLE_HEAVY,
                      header_style="bold magenta",
                      )
results_table.add_column("#", style="cyan", no_wrap=True, width=4)
results_table.add_column("Input")
results_table.add_column("Expected Output")
results_table.add_column("Actual Output")
results_table.add_column("Exit Code", width=4)
results_table.add_column("Time", width=12)  # 添加时间列

summary = {"passed": 0, "failed": 0, "error": 0}
for idx, result in enumerate(results):
    is_passed = result and result.stdout == expected_outputs[idx]
    if is_passed:
        summary["passed"] += 1
    elif result is None:
        summary["error"] += 1
    else:
        summary["failed"] += 1
    row_style = None if is_passed else "on dark_red"
    results_table.add_row(f"{idx + 1}",
                          handle_newline(str(input_data[idx])),
                          handle_newline(expected_outputs[idx]),
                          handle_newline(result.stdout if result else "N/A"),
                          str(result.returncode if result else "N/A"),
                          readable_perf_time(execution_times[idx]) if idx < len(execution_times) else "N/A",  # 显示执行时间
                          style=row_style)
    results_table.add_section()
results_table.caption_justify = "left"
results_table.caption_style = Style(italic=False)
results_table.caption = f"[b]Statics: [green]Passed: {summary['passed']}[/green], [red]Failed: {summary['failed']}[/red], [red]Error: {summary['error']}[/red][/b]"
console.print(
    Panel(results_table,
          title="Test Results Summary",
          border_style="bright_blue"))
print(
    "[green]:tada: [b]Congratulations![/b] :tada: Your code has passed all the tests![/green]\n"
) if summary["passed"] == len(input_data) else print(
    "[red]:boom: [b]Oops![/b] :boom: Your code has failed some tests. Check the code and try again![/red]\n"
)