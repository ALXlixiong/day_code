#include <net/if.h>
#include <unistd.h>
#include <net/if_arp.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/types.h>
#ifdef SOLARIS
#include <sys/sockio.h>
#endif
#define MAXINTERFACES 16 /* 最大接口数 */

int main(int argc, char **argv) {
    register int fd, intrface, retn = 0;
    struct ifreq buf[MAXINTERFACES]; /* ifreq结构数组 */
    struct arpreq arp;
    struct ifconf ifc;
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) >= 0) {
        ifc.ifc_len = sizeof buf;
        ifc.ifc_buf = (caddr_t)buf;
        if (!ioctl(fd, SIOCGIFCONF, (char *)&ifc)) {
            //获取接口数量信息
            intrface = ifc.ifc_len / sizeof(struct ifreq);
            printf("interface num is intrface=%d\n", intrface);
            puts("");
            //根据借口信息循环获取设备IP和MAC地址
            while ((intrface--) > 0) {
                //获取设备名称
                printf("net device %s\n", buf[intrface].ifr_name);

                //判断网卡类型
                if (!(ioctl(fd, SIOCGIFFLAGS, (char *)&buf[intrface]))) {
                    if (buf[intrface].ifr_flags & IFF_PROMISC) {
                        puts("the interface is PROMISC");
                        retn++;
                    }
                } else {
                    char str[256];
                    sprintf(str, "cpm: ioctl device %s",
                            buf[intrface].ifr_name);
                    perror(str);
                }
                //判断网卡状态
                if (buf[intrface].ifr_flags & IFF_UP) {
                    puts("the interface status is UP");
                } else {
                    puts("the interface status is DOWN");
                }
                //获取当前网卡的IP地址
                if (!(ioctl(fd, SIOCGIFADDR, (char *)&buf[intrface]))) {
                    printf("IP address is:");
                    puts((char *)inet_ntoa(
                        ((struct sockaddr_in *)(&buf[intrface].ifr_addr))
                            ->sin_addr));
                    // printf("\n%d\n"buf[intrface].ifr_addr))->sin_addr.s_addr);
                    // puts (buf[intrface].ifr_addr.sa_data);
                } else {
                    char str[256];
                    sprintf(str, "cpm: ioctl device %s",
                            buf[intrface].ifr_name);
                    perror(str);
                }
                /* this section can't get Hardware Address,I don't know whether
                 * the reason is module driver*/
#ifdef SOLARIS
                //获取MAC地址
                arp.arp_pa.sa_family = AF_INET;
                arp.arp_ha.sa_family = AF_INET;
                ((struct sockaddr_in *)&arp.arp_pa)->sin_addr.s_addr =
                    ((struct sockaddr_in *)(&buf[intrface].ifr_addr))
                        ->sin_addr.s_addr;
                if (!(ioctl(fd, SIOCGARP, (char *)&arp))) {
                    printf("HW address is:");
                    //以十六进制显示MAC地址
                    printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
                           (unsigned char)arp.arp_ha.sa_data[0],
                           (unsigned char)arp.arp_ha.sa_data[1],
                           (unsigned char)arp.arp_ha.sa_data[2],
                           (unsigned char)arp.arp_ha.sa_data[3],
                           (unsigned char)arp.arp_ha.sa_data[4],
                           (unsigned char)arp.arp_ha.sa_data[5]);
                    puts("");
                    puts("");
                }
#else
#if 0
                                /*Get HW ADDRESS of the net card */
                                if (!(ioctl (fd, SIOCGENADDR, (char *) &buf[intrface])))
                                {
                                        printf("HW address is:");
                                        printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
                                                        (unsigned char)buf[intrface].ifr_enaddr[0],
                                                        (unsigned char)buf[intrface].ifr_enaddr[1],
                                                        (unsigned char)buf[intrface].ifr_enaddr[2],
                                                        (unsigned char)buf[intrface].ifr_enaddr[3],
                                                        (unsigned char)buf[intrface].ifr_enaddr[4],
                                                        (unsigned char)buf[intrface].ifr_enaddr[5]);
                                        puts("");
                                }
#endif
                if (!(ioctl(fd, SIOCGIFHWADDR, (char *)&buf[intrface]))) {
                    printf("HW address is:");
                    printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
                           (unsigned char)buf[intrface].ifr_hwaddr.sa_data[0],
                           (unsigned char)buf[intrface].ifr_hwaddr.sa_data[1],
                           (unsigned char)buf[intrface].ifr_hwaddr.sa_data[2],
                           (unsigned char)buf[intrface].ifr_hwaddr.sa_data[3],
                           (unsigned char)buf[intrface].ifr_hwaddr.sa_data[4],
                           (unsigned char)buf[intrface].ifr_hwaddr.sa_data[5]);
                }
#endif
                else {
                    char str[256];
                    sprintf(str, "cpm: ioctl device %s",
                            buf[intrface].ifr_name);
                    perror(str);
                }
                //子网掩码
                if (!(ioctl(fd, SIOCGIFNETMASK, (char *)&buf[intrface]))) {
                    printf("MASK:%s",
                           (char *)inet_ntoa(
                               ((struct sockaddr_in *)(&buf[intrface].ifr_addr))
                                   ->sin_addr));
                    puts("");
                } else {
                    char str[256];
                    sprintf(str, "SIOCGIFADDR ioctl %s",
                            buf[intrface].ifr_name);
                    perror(str);
                }
                //广播地址
                if (!(ioctl(fd, SIOCGIFBRDADDR, (char *)&buf[intrface])))
                    printf("Broadcast Address:%s\n",
                           (char *)inet_ntoa(
                               ((struct sockaddr_in *)(&buf[intrface].ifr_addr))
                                   ->sin_addr));

                puts("");
                puts("");
            }  // while
        } else
            perror("cpm: ioctl");
    } else
        perror("cpm: socket");
    close(fd);
    return retn;
}
