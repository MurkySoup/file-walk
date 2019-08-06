/* to compile: use Makefile or gcc -Wall -O2 filewalk.c -o filewalk */

/*
ftw result flags:

FTW_F    fpath is a regular file.

FTW_D    fpath is a directory.

FTW_DNR  fpath is a directory which can't be read.

FTW_NS   The stat(2) call failed on fpath, which is not a symbolic
         link.  The probable cause for this is that the caller had read
         permission on the parent directory, so that the filename fpath
         could be seen, but did not have execute permission, so that
         the file could not be reached for stat(2).

         If fpath is a symbolic link and stat(2) failed, POSIX.1-2001
         states that it is undefined whether FTW_NS or FTW_SL (see
         below) is passed in typeflag.

FTW_DP   fpath is a directory, and FTW_DEPTH was specified in flags.
         (If FTW_DEPTH was not specified in flags, then directories
         will always be visited with typeflag set to FTW_D.)  All of
         the files and subdirectories within fpath have been processed.

FTW_SL   fpath is a symbolic link, and FTW_PHYS was set in flags.

FTW_SLN  fpath is a symbolic link pointing to a nonexistent file.
         (This occurs only if FTW_PHYS is not set.)

Ref: http://man7.org/linux/man-pages/man3/nftw.3.html
*/

#define _XOPEN_SOURCE 500 /* required beause Linux still uses SUSv1 for this API */
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static int display_info (const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf) {
/* full display
  printf ("%-3s %2d %7jd   %-40s %d %s\n",
    (tflag == FTW_D) ?   "d"   : (tflag == FTW_DNR) ? "dnr" :
    (tflag == FTW_DP) ?  "dp"  : (tflag == FTW_F) ?   "f" :
    (tflag == FTW_NS) ?  "ns"  : (tflag == FTW_SL) ?  "sl" :
    (tflag == FTW_SLN) ? "sln" : "???",
    ftwbuf->level, (intmax_t) sb->st_size,
    fpath, ftwbuf->base, fpath + ftwbuf->base);
*/

  printf ("%-3s %-40s\n",
    (tflag == FTW_D) ?   "d"   : (tflag == FTW_DNR) ? "dnr" :
    (tflag == FTW_DP) ?  "dp"  : (tflag == FTW_F) ?   "f" :
    (tflag == FTW_NS) ?  "ns"  : (tflag == FTW_SL) ?  "sl" :
    (tflag == FTW_SLN) ? "sln" : "???", fpath);

  return (0);
}

int main (int argc, char *argv[]) {
  int flags = 0;

  if (argc > 2 && strchr (argv[2], 'd') != NULL) {
    flags |= FTW_DEPTH; }

  if (argc > 2 && strchr (argv[2], 'p') != NULL) {
    flags |= FTW_PHYS; }

  if (nftw((argc < 2) ? "." : argv[1], display_info, 20, flags) == -1) {
    perror ("nftw");

    exit (EXIT_FAILURE); }

  exit (EXIT_SUCCESS);
}

/* end of source (filewalk.c) */
