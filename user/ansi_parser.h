#ifndef ANSI_PARSER_H
#define ANSI_PARSER_H

#include <stdlib.h>

// Max nr of CSI parameters
#define CSI_N_MAX 3

extern void apars_handle_badseq(void);
extern void apars_handle_CSI(char leadchar, int *params, char keychar);
extern void apars_handle_RESET_cmd(void);
extern void apars_handle_plainchar(char c);
extern void apars_handle_OSC_FactoryReset(void);
extern void apars_handle_OSC_SetScreenSize(int rows, int cols);
extern void apars_handle_saveCursorAttrs(void);
extern void apars_handle_restoreCursorAttrs(void);

/**
 * \brief Linear ANSI chars stream parser
 * 
 * Parses a stream of bytes using a Ragel parser. The defined
 * grammar does not use 'unget', so the entire buffer is 
 * always processed in a linear manner.
 * 
 * \attention -> but always check the Ragel output for 'p--' 
 *            or 'p -=', that means trouble.
 * 
 * \param newdata - array of new chars to process
 * \param len - length of the newdata buffer
 */
void ansi_parser(const char *newdata, size_t len);

#endif // ANSI_PARSER_H
