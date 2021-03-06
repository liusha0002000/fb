#ifndef __FBTOOL_H_
#define __FBTOOL_H_

#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <stddef.h>
#include <string.h>
#include <sys/mman.h>
#include <math.h>
#include <stdint.h>
#include "page.h"

typedef struct fbdev{
	int fb;   //framebuffer打开后的唯一标识符
	struct fb_fix_screeninfo fb_fix;
	struct fb_var_screeninfo fb_var;
	/* 新增 */
	unsigned long fb_mem_offset; //frame buffer所占内存的偏移量
	unsigned long fb_mem; //frame buffer的映射到进程内存空间的起始地址

	char dev[20];
}FBDEV,*PFBDEV;

typedef struct point{
	int x;
	int y;
	int z;
}POINT,*PPOINT;

//打开framebuffer
int fb_open(PFBDEV pFbdev);
//关闭framebuffer
int fb_close(PFBDEV pFbdev);
//打印frame buffer 所占内存的开始地址　
void pmem_start(PFBDEV pFbdev);
//打印FB_TYPE
void p_type(PFBDEV pFbdev);
//打印可见清晰度
void p_visible_res(PFBDEV pFbdev);
//打印虚拟分辨率
void p_virt_res(PFBDEV pFbdev);
//打印虚拟到可见的偏移量
void p_offset(PFBDEV pFbdev);
//打印每个像素的位数
void p_bpp(PFBDEV pFbdev);
//打印R,G,B和透明度
void p_rgbt(PFBDEV pFbdev);
//打印在内存中的高度和宽度
void p_hw(PFBDEV pFbdev);
//清空控制台　
void clear_con(void *addr,int n,size_t len);
//映射到内存
void fb_memcpy(void *addr,void *color,size_t len);
//画点
void draw_dot(PFBDEV pFbdev,POINT p,uint8_t r,uint8_t g,uint8_t b);
//画横线
void draw_h_line(PFBDEV pFbdev,POINT minX,POINT maxX,uint8_t r,uint8_t g,uint8_t b);
//画竖线
void draw_v_line(PFBDEV pFbdev,POINT minY,POINT maxY,uint8_t r,uint8_t g,uint8_t b);
//画一个矩形框
void draw_rec(PFBDEV pFbdev,POINT lu,POINT ld,POINT ru,POINT rd,uint8_t r,uint8_t g,uint8_t b);
//填充一个矩形框
void fill_rec(PFBDEV pFbdev,POINT lu,POINT ld,POINT ru,POINT rd,uint8_t r,uint8_t g,uint8_t b);
#endif












