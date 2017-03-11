#include <ring_buff.h>


int main(int argc, char *argv[])
{
    ring_buff<int, 10>crc_buf;

    for(int i = 0; i < 5; i++)
    {
        crc_buf.push(i);
    }
    cout << crc_buf << endl;

    //tests heve done!!!


    return 0;
}
