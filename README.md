minimal-init-new is a simple page of code to create the init binary for minimal-linux-new.  its intended purpose is to better understand the basics of coding and system initiation.  once compiled, it can be used to start the minimal-linux-new system.  it's very easy and fun, just follow the steps (see also minimal-linux-new text).

obtain minimal-init-new (ex. for minimal-linux-new on /dev/sda8):

https://github.com/skewish/minimal-init-new/ (newest release) --> /mnt/sda8/tmp
cd /mnt/sda8/tmp
tar -x -f minimal-init-new*
rm minimal-init-new*.tar.gz
chown -R 0:0 /mnt/sda8/tmp

compile & install minimal-init-new:

~# cd /mnt/sda8/tmp/minimal-init-new*/
~# gcc -static -o init minimal-init-new.c
~# cp -p init /mnt/sda8/sbin
