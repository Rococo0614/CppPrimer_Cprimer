#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


char *my_strdup(const char *s) {
    if (s == NULL) return NULL;
    size_t len = strlen(s) + 1;
    char *copy = malloc(len);
    if (copy) memcpy(copy, s, len);
    return copy;
}
// 读取一行输入（已优化）
char *get_string() {
    char buffer[201]; // 题目限制长度≤200
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return NULL;
    }
    // 去除末尾的换行符
    buffer[strcspn(buffer, "\n")] = '\0';
    return my_strdup(buffer);
}



// 检查是否为完整单词匹配
bool is_whole_word(const char *str, const char *word, size_t pos, size_t word_len) {
    // 检查左侧边界（空格或字符串开头）
    if (pos > 0 && str[pos - 1] != ' ') {
        return false;
    }
    // 检查右侧边界（空格或字符串结尾）
    if (str[pos + word_len] != '\0' && str[pos + word_len] != ' ') {
        return false;
    }
    return true;
}

// 替换单词（核心函数）
char *replace_words(const char *str, const char *old_word, const char *new_word) {
    size_t old_len = strlen(old_word);
    size_t new_len = strlen(new_word);
    size_t str_len = strlen(str);
    
    // 计算最大可能长度
    size_t max_len = str_len + 200; // 预留足够空间
    char *result = malloc(max_len);
    if (!result) return NULL;
    
    char *dest = result;
    const char *src = str;
    const char *found;
    
    while ((found = strstr(src, old_word)) != NULL) {
        // 检查是否为完整单词
        size_t pos = found - src;
        if (!is_whole_word(src, old_word, pos, old_len)) {
            size_t copy_len = pos + old_len;
            memcpy(dest, src, copy_len);
            dest += copy_len;
            src += copy_len;
            continue;
        }
        
        // 复制前缀
        size_t prefix_len = pos;
        memcpy(dest, src, prefix_len);
        dest += prefix_len;
        
        // 复制新单词
        memcpy(dest, new_word, new_len);
        dest += new_len;
        
        // 跳过原单词
        src += prefix_len + old_len;
    }
    
    // 复制剩余部分
    strcpy(dest, src);
    return result;
}

int main() {
    char *str = get_string();
    char *old_word = get_string();
    char *new_word = get_string();
    
    if (!str || !old_word || !new_word) {
        printf("Input error\n");
        free(str);
        free(old_word);
        free(new_word);
        return 1;
    }
    
    char *new_str = replace_words(str, old_word, new_word);
    if (!new_str) {
        printf("Replacement failed\n");
    } else {
        printf("%s\n", new_str);
    }
    
    free(str);
    free(old_word);
    free(new_word);
    free(new_str);
    return 0;
}