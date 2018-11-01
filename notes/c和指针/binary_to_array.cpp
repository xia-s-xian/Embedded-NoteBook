#include "stdafx.h"
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h> 
#include "string.h"

unsigned int GetFileSize(char *filename);
void read_src(char *path, unsigned char *buf, unsigned int size);
void make_dstfile(char *outpath, unsigned char *buf, unsigned int size);

int main()
{
unsigned char *buf = NULL;

unsigned int size;
char srcbmp[100]={0};
char dstfile[100]={0};
//char srcbmp[100]="test.bin";
//char dstfile[100]="test.h";
printf("Please input src file name\nC file path name\n");
scanf("%s %s",srcbmp,dstfile);
size = GetFileSize(srcbmp);
buf = (unsigned char *)malloc(sizeof(unsigned char)*size);

read_src(srcbmp, buf, size);

make_dstfile(dstfile, buf, size);
	return 0;
}
unsigned int GetFileSize(char *filename)
{   
	unsigned int  siz = 0;   
	FILE  *fp = fopen(filename, "rb");   
	if (fp) 
	{      
		fseek(fp, 0, SEEK_END);      
		siz = ftell(fp);      
		fclose(fp);   
	}   
	return siz;
}

void read_src(char *path, unsigned char *buf, unsigned int size)
{
	FILE *infile;
	
	if((infile=fopen(path,"rb"))==NULL)
	{
		printf( "\nCan not open the path: %s \n", path);
		exit(-1);
	}

	fread(buf, sizeof(unsigned char), size, infile);//printf("\n�򿪵�ͼΪ %d",img->bfType);
	
	fclose(infile);
}
void make_dstfile(char *outpath, unsigned char *buf, unsigned int size)
{
	FILE *infile;
	int i,j,k,n;
	char pbuf[10]={0};
	if((infile=fopen(outpath,"wa+"))==NULL)
	{
		printf( "\nCan not open the path: %s \n", outpath);
		exit(-1);
	}
	k=0;

	fwrite("u8 temp_array[] = {\n",strlen("u8 m_firmware_data_200[] = {\n"),1,infile);
	for(i = 0; i < size; i++)
	{
			k++;
			sprintf(pbuf,"0x%02x",buf[i]);
			fwrite(pbuf,strlen(pbuf),1,infile);
			if(k != 8)
			fwrite(", ",strlen(", "),1,infile);
			else
			fwrite(",",strlen(","),1,infile);	
		
			if(k==8)
			{
				k=0;
				fwrite("\n",strlen("\n"),1,infile);

			}
		
	}

	fseek(infile,0,SEEK_END);
	if(k == 0)
		fwrite("};",strlen("};"),1,infile);
	else
		fwrite("\n};",strlen("\n};"),1,infile);


	fclose(infile);
}
