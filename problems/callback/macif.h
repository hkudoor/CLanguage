#ifndef _MACIF_H_
#define _MACIF_H_

// enums
typedef enum _bool {
    false,
    true
} bool;

// Interface

typedef struct _tDiscStatus {
    bool enabled;
    unsigned int numPcu;
    unsigned int numAcb;
    unsigned int minutesRemaining;
} tDiscStatus;

/* callback function pointer */
typedef void (*pDiscoveryStatus)(tDiscStatus status);

void macIfGetDiscoveryStatus(pDiscoveryStatus cb);

#endif
