#include<stdlib.h>
#include<stdio.h>
#include<macif.h>

// globals

tDiscStatus gDiscoveryStatus;


// helper functions

void updateDiscoveryStatus(bool status, unsigned int numPcu, unsigned int numAcb, unsigned int minRemaining) {
    gDiscoveryStatus.enabled = status;
    gDiscoveryStatus.numPcu = numPcu;
    gDiscoveryStatus.numAcb = numAcb;
    gDiscoveryStatus.minutesRemaining = minRemaining;
}

// Interface

/* get discovery status */
void macIfGetDiscoveryStatus(pDiscoveryStatus cb) {
    updateDiscoveryStatus(true, 5, 5, 8);
    cb(gDiscoveryStatus);
}
