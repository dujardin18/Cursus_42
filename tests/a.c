#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <uuid/uuid.h>
#include <sys/xattr.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
	struct stat buf;
	struct stat buf2;
	char c;
	ssize_t tst;
	ssize_t tst2;
	time_t tmp = time(NULL);

	if(stat(argv[1],&buf) < 0)    
		        return 1;
	if(lstat(argv[1],&buf2) < 0)    
		        return 1;

	printf("Information for %s\n",argv[1]);
	printf("---------------------------\n");
	printf("File Size: \t\t%d bytes\n",buf.st_size);
	printf("Number of Links: \t%d\n",buf.st_nlink);
	printf("File inode: \t\t%d\n",buf.st_ino);

	printf("File Permissions: \t");
	if (buf.st_mode & S_IFDIR)
		c = 'd';
	else if (buf.st_mode & S_IFREG)
		c = '-';
	printf("%c", c);
	printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
	printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
	printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
	printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
	printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
	printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
	printf( (buf.st_mode & S_IROTH) ? "r" : "-");
	printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
	printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
	printf("\nlast modified = %s", ctime(&(buf.st_mtimespec.tv_sec)));
	printf("\nUser : %s", getpwuid(buf.st_uid)->pw_name);
	printf("\ngroup : %s", getgrgid(buf.st_gid)->gr_name);
	printf("\nopti : %d %d", buf.st_blocks, buf2.st_blocks);
	tst = listxattr(argv[1], NULL, 0, XATTR_NOFOLLOW);
	tst2 = getxattr(argv[1], NULL, NULL, 0, 0, XATTR_NOFOLLOW);
	printf("\ntst : %lld > %lld", tst, tst2);
	printf("\ntime %lld\n", tmp);
	printf("\n\n");

	printf("The file %s a symbolic link\n", (S_ISLNK(buf.st_mode)) ? "is" : "is not");
	return (0);
}
