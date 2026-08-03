/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viego </var/spool/mail/viego>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:21:43 by viego             #+#    #+#             */
/*   Updated: 2026/08/03 15:21:43 by viego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framebuffer.h"

int ft_fb_init(t_fb *fb) {
	if ((fb->fd = open("/dev/fb0", O_RDWR)) < 0) {
		perror("/dev/fb0");
		return -1;
	}
	if (ioctl(fb->fd, FBIOGET_VSCREENINFO, &fb->vinfo)) {
		perror("ioctl");
		return -1;
	}
	if (ioctl(fb->fd, FBIOGET_FSCREENINFO, &fb->finfo)) {
		perror("ioctl");
		return -1;
	}
	fb->screensize = fb->vinfo.yres_virtual * fb->finfo.line_length;
	if ((fb->map = mmap(NULL, fb->screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fb->fd, 0)) == MAP_FAILED) {
		perror("mmap");
		return -1;
	}
	return 0;
}
