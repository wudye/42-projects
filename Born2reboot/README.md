install	VirtualBox(installed by 42) and install Debian
1. check systeme all information: uname -a
2. check computer all information: (sudo) lshw / lshw -short
3. check CPU information: (sudo) lscpu
4. check block(disk) devices: lsblk / lsblk -a
5. check USB Controller: lsusb
6. check Ubuntu version info: lsb_release -a  // lsb = linux standard base
7. download Debiani install it

what is a hostname?
	 A hostname is a name given to a computer and attached to the network. 
Its main purpose is to uniquely identify over a network.

check hostname: hostname

Domainname?
	 the domain name is the mapping of IP with the name. 
Domain names are registered in the DNS server in case of a local network.

check domainname: domainname -A

f.g: bitsy.mit.edu
	bitsy is hostname
	mit.edu is domainname

primary and logical partition

primary 
is the only partition that can be set active for BIOS to locate. 
In other words, you can only boot from a primary partition.
 Generally, a disk drive can contain a maximum of 4 primary partitions 
or 3 primary partitions and a single extended partition.

logical
it is a logical segmentation of a mainframe's memory and other resources 
that allows it to run its own copy of the operating system and associated applications. 
The number of logical partitions in an MBR disk is limitless. 

MBR : primary partition
	  primary partition
	  primary partition
	  extended partition   logical partition
						   logical partition
						   ...

primary partition is more important, is essential to an MBR disk. Without it, you can not boot your pc.
primary has no more than 4, logical is unlimited.

MBR(Master Boot Record) disk is the first sector of a hard disk or removable disk.  It identifies how and 
where the system's operating system (OS) is located in order to be booted (loaded) into the computer's 
main storage or random access memory (RAM).
		
GUID partition table (GPT) disks use the Unified Extensible Firmware Interface (UEFI). One advantage of 
GPT disks is that you can have more than four partitions on each disk. GPT is also required for disks larger 
than 2 terabytes (TB).

file system
A file system is a structure used by an operating system to organise and manage files on a storage device 
such as a hard drive, solid state drive (SSD), or USB flash drive. It defines how data is stored, accessed, 
and organised on the storage device. 

FAT (File Allocation Table), FAT16, FAT32
 It was initially developed for MS-DOS and is still used in many removable storage devices. 

exFAT (Extended File Allocation Table)
exFAT is a file system introduced by Microsoft as an improved version of FAT32. 

NTFS (New Technology File System)

Ext4 (Fourth Extended File System)
A widely used file system in the Linux operating system. It is the successor to Ext3 and offers several improvements in terms of performance, scalability, and reliability. Ext4 is the default file system for many Linux distributions. It was first introduced in 2003.

partitions
	/ 		-the root file system
	/boot	-static files of the boot loader
	/home	-user home directories
	/tmp 	-temporary files
	/usr	-static data
	/var	-variable data
	/srv	-data for services provided by this system
	/opt	-add-on application software packages
	/usr/local	-a local hierarchy

GNU GRUB
GNU GRUB is a Multiboot boot loader. It was derived from GRUB, the GRand Unified Bootloader,
 which was originally designed and implemented by Erich Stefan Boleyn.

Briefly, a boot loader is the first software program that runs when a computer starts. 
It is responsible for loading and transferring control to the operating system kernel software 
(such as the Hurd or Linux). The kernel, in turn, initializes the rest of the operating system (e.g. GNU).

8. beginn to install sudo

 differen su and sudo
 su is to switch to root.
 sudo is a way to allow a user to temporarily run a program with expanded security privileges -- to delegate specific tasks rather than fully elevating privileges to root systemwide. Delegation enables specific tasks to be assigned to specific users or groups.
use command: whoami

lsblk	list block devices

apt		a command-line utility for installing, updating, removing

sudo config
The configuration file for sudo is /etc/sudoers . It should always be edited with the visudo(8) command. visudo locks the sudoers file, saves edits to a temporary file, and checks it for syntax errors before copying it to /etc/sudoers .
	
VPNs and SSH systems both create secure “tunnels” for your data to travel through. These tunnels ensure that nobody other than the intended recipient can view or alter your data.
However, while an SSH connection only works on an application level, a VPN connection encrypts and protects all your data.

SSH stands for “Secure Shell.” 
VPN A Virtual Private Network is a technology that protects your privacy online by routing your traffic through an encrypted tunnel. 


UFW is a great firewall tool that is designed to be run on hosts or servers. It allows or blocks incoming and outgoing connections to and from the server. You can block ports, IPs or even entire subnets using UFW.

libpam-pwquality install
The libpwquality library purpose is to provide common functions for password quality checking and also scoring them based on their apparent randomness. The library also provides a function for generating random passwords with good pronounceability.


