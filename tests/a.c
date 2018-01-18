#include <sys/stat.h>

int main(int argc, char **argv)
{
	struct stat buf;

	if(stat(argv[1],&buf) < 0)    
		        return 1;

	printf("Information for %s\n",argv[1]);
	printf("---------------------------\n");
	printf("File Size: \t\t%d bytes\n",buf.st_size);
	printf("Number of Links: \t%d\n",buf.st_nlink);
	printf("File inode: \t\t%d\n",buf.st_ino);

	printf("File Permissions: \t");
	printf( (S_ISDIR(buf.st_mode)) ? "d" : "-");
	printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
	printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
	printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
	printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
	printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
	printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
	printf( (buf.st_mode & S_IROTH) ? "r" : "-");
	printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
	printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n\n");

	printf("The file %s a symbolic link\n", (S_ISLNK(buf.st_mode)) ? "is" : "is not");
	return (0);
}
