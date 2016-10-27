#include<stdlib.h>
#include<stdio.h>
#include<macif.h>

// globals
tDiscStatus gStatus = {false, 0, 0, 0};

// helper functions
void setNewStatus(tDiscStatus newStatus) {
    gStatus = newStatus;
}

void printDiscoveryStatus(tDiscStatus* status) {
    printf("------------------\n");
    printf("Status : %s\n", ((status->enabled == true) ? "ENABLED" : "DISABLED"));
    printf("Num of PCU : %d\n", status->numPcu);
    printf("Num of ACB : %d\n", status->numAcb);
    printf("Time Remaining : %d\n", status->minutesRemaining);
    printf("\n");
}


// main
void main() {
    printf("discovery status at start :\n");
    printDiscoveryStatus(&gStatus);

    printf("Getting latest discovery status..\n");
    macIfGetDiscoveryStatus(setNewStatus);
    
    printf("latest status :\n");
    printDiscoveryStatus(&gStatus);
}
