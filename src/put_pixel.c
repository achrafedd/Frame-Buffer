#include "framebuffer.h"

void ft_put_pixel(t_fb *fb, int x, int y, uint32_t color) {
	int pixel;
	pixel = (x + fb->vinfo.xoffset) * (fb->vinfo.bits_per_pixel / 8) + (y + fb->vinfo.yoffset) * fb->finfo.line_length;
	*((uint32_t *) (fb->map + pixel)) = color;
}
