#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    int n, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    
    // 读取n
    char temp[4];
    fgets(temp, sizeof(temp), stdin);
    n = atoi(temp);
	// scanf("%d", &n);
	// getchar();
    
    char b[n][32];
    
    // 读取n个字符串
    for(int i = 0; i < n; i++){
        fgets(b[i], 32, stdin);
        
        // 移除fgets读取的换行符
        size_t len = strlen(b[i]);
        if(len > 0 && b[i][len-1] == '\n'){
            b[i][len-1] = '\0';
        }
    }
    
    for(int i = 0; i < n; i++){
        int password_len = strlen(b[i]);
        
        // 检查空密码情况
        // if(password_len == 0){
        //     printf("Not Safe\n");
        //     continue;
        // }
        
        // 检查密码长度
        if(password_len < 6){
            printf("Not Safe\n");
            continue;
        }
        
        // 重置计数器
        cnt1 = 0; cnt2 = 0; cnt3 = 0; cnt4 = 0;
        
        // 检查字符类型
        for(int j = 0; j < password_len; j++){
            if(b[i][j] >= '0' && b[i][j] <= '9'){
                if(cnt1 == 0)
                    cnt1++;
            }
            else if(b[i][j] >= 'A' && b[i][j] <= 'Z'){
                if(cnt2 == 0)
                    cnt2++;
            }
            else if(b[i][j] >= 'a' && b[i][j] <= 'z'){
                if(cnt3 == 0)
                    cnt3++;
            }
            else{
                if(cnt4 == 0)
                    cnt4++;
            }    
        }
        
        // 根据字符类型数量判断安全性
        switch(cnt1 + cnt2 + cnt3 + cnt4){
            case 1:
                printf("Not Safe\n");
                break;
            case 2:
                printf("Medium Safe\n");
                break;
            case 3:
            case 4:
                printf("Safe\n");
                break;
        }
    }
    return 0;
}