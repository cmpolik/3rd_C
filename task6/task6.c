#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>

void access(mode_t st_mode, char* syb) {   
    syb[0] = st_mode & S_IRUSR ? 'r' : '-';   
    syb[1] = st_mode & S_IWUSR ? 'w' : '-';     
    syb[2] = st_mode & S_IXUSR ? 'x' : '-';
    syb[3] = st_mode & S_IRGRP ? 'r' : '-';
    syb[4] = st_mode & S_IWGRP ? 'w' : '-';    
    syb[5] = st_mode & S_IXGRP ? 'x' : '-';
    syb[6] = st_mode & S_IROTH ? 'r' : '-';
    syb[7] = st_mode & S_IWOTH ? 'w' : '-';
    syb[8] = st_mode & S_IXOTH ? 'x' : '-';
}

const char tipe(unsigned mod)
{
	switch (mod & S_IFMT) {
		case S_IFBLK:  return 'b';
		case S_IFCHR:  return 'c';
		case S_IFDIR:  return 'd';
		case S_IFIFO:  return 'p';
		case S_IFLNK:  return 'l';
		case S_IFREG:  return '-';
		case S_IFSOCK: return 's';
		default:       return '?';
	}
}

char dtype(unsigned char dtype) {

	switch (dtype) {
		case DT_BLK:      return 'b'; 
		case DT_CHR:      return 'c'; 
		case DT_DIR:      return 'd';
		case DT_FIFO:     return 'f';
		case DT_LNK:      return 'l'; 
		case DT_REG:      return 'r';
		case DT_SOCK:     return 's';
		case DT_UNKNOWN:  return '?';
	}

	return '?';
}

int main() {
	DIR *dir = opendir(".");

    if (!dir) {
		perror("ничего не имеет смысла");
        return 1;
	}
    struct dirent* entry;

	while ((entry = readdir(dir)) != NULL) {
		char entry_type = dtype(entry->d_type);
		struct stat sb;
		assert((lstat(entry->d_name, &sb)) == 0);
		access(sb.st_mode);
		if (entry_type == '?') entry_type = tipe(sb.st_mode);
		printf(" %c %s\n", entry_type, entry->d_name);
	}

	closedir(dir);
	return 0;
}
