#include "framebuffer.h"

int main(void)
{
	t_fb fb;
	int status;

	if ((status = ft_fb_init(&fb)))
		return status;
	ft_fb_destroy(&fb);
	return 0;
}
