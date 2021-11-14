.PHONY: initramfs run clean

initramfs:
	@mkdir -p build
	@cd initramfs && find . -print0 | cpio --null -ov --format=newc | gzip -9 \
	  > ../build/initramfs-busybox-x86.cpio.gz

run:
	@qemu-system-x86_64 \
	  -cpu core2duo \
	  -kernel vmlinuz-minimal \
	  -initrd build/initramfs-busybox-x86.cpio.gz \
	  -nographic -append "console=ttyS0 quiet splash acpi=off"

clean:
	@rm -rf build
