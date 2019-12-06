// My macros

// Macros for mathamatical operatiion

#define ABSOLUTE_VALUE(x)	(x < 0 ? -(x) : x)
#define MAX(a, b)		(a > b ? a : b)
#define MIN(a, b)		(a < b ? a : b)

/*
 * (#, ##)
 * The # and ## operators are used with the #define macro.
 * Using # causes the first argument after the # to be returned as a string in quotes.
 * 
 * For example, the command
 * 
 * #define as_string( s ) # s
 * 
 * will make the compiler turn this command
 *
 * puts( as_string( Hello World! ) ) ;
 *
 * into
 *
 * puts( "Hello World!" );
 *
 * Using ## concatenates what's before the ## with what's after it. For example, the command
 *
 * #define concatenate( x, y ) x ## y
 *
 * ...
 *
 * int xy = 10;
 *
 * ...
 *
 * will make the compiler turn
 *
 * printf( "%d", concatenate( x, y ));
 *
 * into
 *
 * printf( "%d", xy);
 *
 */

#define concat(x, y) x##y
#define to_string(s) #s

