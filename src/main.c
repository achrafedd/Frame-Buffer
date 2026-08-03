#include "framebuffer.h"

int main(void)
{
	t_fb fb;
	int status;

	if ((status = ft_fb_init(&fb)))
		return status;
	ft_fill_rect(&fb, 100, 100, 800, 400, 0xFFFF00FF);
	ft_fb_destroy(&fb);
	return 0;
}
