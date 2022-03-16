#include <stdio.h>
#include <stdlib.h>
#define MAX_LIMIT 50
FILE *pFile;

int hi(value){
    int pix;
    printf("\n\ninput %s\n", value);
    scanf("%d",&pix);
    return pix;
}

void tag(tag_name){
    char tag_value[MAX_LIMIT], href[MAX_LIMIT], valueHref[MAX_LIMIT], img[MAX_LIMIT], newTag[MAX_LIMIT], nameTag[MAX_LIMIT];
    if(!strcmp(tag_name,"a"))
    {
        printf("\n\ninput the URL\n");
        scanf("%s",&href);
        printf("\n\ninput link text\n", valueHref);
        scanf(" %[^\t\n]s",&valueHref);
        pFile=fopen("index.html", "a");
        fprintf(pFile,"\n    <a href=\"%s\"> %s </a>\n", href, valueHref);
        fclose(pFile);
    }
    else if(!strcmp(tag_name,"img"))
    {
        printf("\n\ninput link img\n");
        scanf(" %[^\t\n]s",&img);
        pFile=fopen("index.html", "a");
        fprintf(pFile,"    <img src=\"%s\" style=\"width:%dpx;height:%dpx;\">\n", img, hi("width"), hi("height"));
        fclose(pFile);
    }
    else if(!strcmp(tag_name,"div"))
    {
        printf("\n\n do you want a new tag inside div (yes\ no)\n");
        scanf(" %s",&newTag);
        if(!strcmp(newTag,"yes")){
            printf("\n\ninput name of tag\n");
            scanf(" %s", nameTag);
            pFile=fopen("index.html", "a");
            fprintf(pFile,"    <div>\n    ");
            fclose(pFile);
            tag(nameTag);
            pFile=fopen("index.html", "a");
            fprintf(pFile,"    </div>\n");
            fclose(pFile);
        }else{
            pFile=fopen("index.html", "a");
            fprintf(pFile,"    <div>\n    \n    </div>\n");
            fclose(pFile);
        }
    }
    else
    {
        printf("\n\ninput value of %s\n", tag_name);
        scanf(" %[^\t\n]s",&tag_value);
        pFile=fopen("index.html", "a");
        fprintf(pFile,"    <%s> %s </%s>\n", tag_name, tag_value, tag_name);
        fclose(pFile);
    }
}

int main()
{
    FILE *pFile;
    char title[30], nameOfTag[30];

    while(1){
        printf("Input title of header\n");
        scanf(" %[^\t\n]s", title);
        if (!strcmp(title,"exit")){
            break;
        }
        else{
            pFile=fopen("index.html", "w");
            fprintf(pFile,"<!DOCTYPE html>\n<html>\n<head>\n   <title>%s</title>\n   <meta charset=\"UTF-8\">\n</head>\n<body>\n", title);
            fclose(pFile);
            while(1){
                printf("\n\ninput name of tag exit to break\n");
                scanf(" %[^\t\n]s", nameOfTag);
                if(!strcmp(nameOfTag,"exit")){ break;}
                tag(nameOfTag);
            }
            pFile=fopen("index.html", "a");
            fprintf(pFile,"</body>\n</html> ");
            fclose(pFile);
            break;
        }

    }

    return 0;
}
