// 顺序串的数据类型：
#define STR_LEN     100
typedef struct string
{
    char elem[STR_LEN + 1];  // 为了方便操作，一般不用elem[0]来存储数据；
    int length;
} String;


// 链串的数据类型：
#define CHUNK_LEN   10
typedef struct chunk 
{
    char elemChunk[CHUNK_LEN];
    struct listString * pNext;
} Chunk;

typedef struct listString
{
    char * head, * tail;
    int stringLen;
} ListString;
