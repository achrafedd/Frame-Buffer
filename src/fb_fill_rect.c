#include "framebuffer.h"

void ft_fill_rect(t_fb *fb, int x, int y, int w, int h, uint32_t color) {
	int radius = 20;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (i + j > radius && (i - j) < w - radius)
				ft_put_pixel(fb, x + i, y + j, color);
		}
	}
}
