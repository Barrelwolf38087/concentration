#ifndef CONCENTRATION_H
#define CONCENTRATION_H

#ifdef _WIN32
    unsigned int doWindows(unsigned int uiDIFFICULTY, int iaNums[]);
#else
    unsigned int doOther(unsigned int uiDIFFICULTY, int iaNums[]);
#endif

#endif
