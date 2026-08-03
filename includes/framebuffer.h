#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

# include <stdint.h>
# include <sys/ioctl.h>
# include <sys/mman.h>
# include <linux/fb.h>
# include <linux/input.h>
# include <time.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_fb {
    int                        fd;
    struct fb_var_screeninfo   vinfo;
    struct fb_fix_screeninfo   finfo;
    uint8_t                    *map;      // mmap'd framebuffer
    uint8_t                    *back;     // bonus: off-screen buffer
    long                       screensize;
} t_fb;

int ft_fb_init(t_fb *fb);
void ft_fb_destroy(t_fb *fb);
void ft_put_pixel(t_fb *fb, int x, int y, uint32_t color);

#endif // !FRAMEBUFFER_H
