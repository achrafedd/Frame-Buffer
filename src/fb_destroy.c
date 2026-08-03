#include "framebuffer.h"

void ft_fb_destroy(t_fb *fb) {
	munmap(fb->map, fb->screensize);
	close(fb->fd);
}
