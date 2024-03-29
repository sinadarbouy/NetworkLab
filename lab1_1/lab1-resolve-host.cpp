/********************************************************* -- SOURCE -{{{1- */
/** Translate host name into IPv4
 *
 * Resolve IPv4 address for a given host name. The host name is specified as
 * the first command line argument to the program.
 *
 * Build program:
 *  $ g++ -Wall -g -o resolve <file>.cpp
 */
/******************************************************************* -}}}1- */
#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/inet.h>

//--//////////////////////////////////////////////////////////////////////////
//--    local declarations          ///{{{1///////////////////////////////////
void print_usage(const char *aProgramName);
//--    local config                ///{{{1///////////////////////////////////
/* HOST_NAME_MAX may be missing, e.g. if you're running this on an MacOS X
 * machine. In that case, use MAXHOSTNAMELEN from <sys/param.h>. Otherwise
 * generate an compiler error.
 */
#if !defined(HOST_NAME_MAX)
#if defined(__APPLE__)
#include <sys/param.h>
#define HOST_NAME_MAX MAXHOSTNAMELEN
#else // !__APPLE__
#error "HOST_NAME_MAX undefined!"
#endif // ~ __APPLE__
#endif // ~ HOST_NAME_MAX
//--    main()                      ///{{{1///////////////////////////////////
int main(int aArgc, char *aArgv[])
{
    // Check if the user supplied a command line argument.
    if (aArgc != 2)
    {
        print_usage(aArgv[0]);
        return 1;
    }
    // The (only) argument is the remote host that we should resolve.
    const char *remoteHostName = aArgv[1];
    // Get the local host's name (i.e. the machine that the program is
    // currently running on).
    const size_t kHostNameMaxLength = HOST_NAME_MAX + 1;
    char localHostName[kHostNameMaxLength];
    if (-1 == gethostname(localHostName, kHostNameMaxLength))
    {
        if (errno == ENAMETOOLONG)
            fprintf(stderr, "error %d: len is smaller than the actual size!", errno);
        if (errno == EFAULT)
            fprintf(stderr, "error %d: name is an invalid address.", errno);
        return 1;
    }
    // Print the initial message
    printf("Resolving `%s' from `%s':\n", remoteHostName, localHostName);

    // set hints for getaddrinfo
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo)); // fill memory with a constant byte
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;     /* For wildcard IP address */
    hints.ai_protocol = IPPROTO_TCP; /* won’t get “duplicate” IPv4 addresses */
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;

    struct addrinfo *result;

    int res;
    res = getaddrinfo(remoteHostName, NULL, &hints, &result);

    // show errors
    if (res != 0)
    {
        fprintf(stderr, "Error: %s\n", gai_strerror(res)); // human-readable
        return 1;
    }

    // IPv4 addresses
    struct sockaddr_in *addr;
    addr = (sockaddr_in *)result->ai_addr;
    printf("%s has address IPv4 %s\n", remoteHostName, inet_ntoa((in_addr)addr->sin_addr));

    // IPv6 addresses
    char buf[INET6_ADDRSTRLEN];
    struct sockaddr_in6 *addrip6;
    addrip6 = (sockaddr_in6 *)result->ai_next;
    printf("%s has address IPv6 %s\n", remoteHostName, inet_ntop(AF_INET6, &addrip6->sin6_addr, buf, INET6_ADDRSTRLEN));

    freeaddrinfo(result);
    // Ok, we're done. Return success.
    return 0;
}
//--    print_usage()               ///{{{1///////////////////////////////////
void print_usage(const char *aProgramName)
{
    fprintf(stderr, "Usage: %s <hostname>\n", aProgramName);
}
//--///}}}1/////////////// vim:syntax=cpp:foldmethod=marker:ts=4:noexpandtab:
