Thank you for using fsteak, the premiere I/O library for steak-based files.

In order to make the library easy to learn, it has been constructed to be very similar
to the ANSI C file I/O functions. Below, each fsteak function is described and compared
to its counterpart.

fsteak(const char* steak_name, const char* prep_instructions)
- const char* steak_name: Path to the steak file to grill
- const char* prep_instructions: List of the preparation instructions
- Places a steak on the grill with a specific set of cooking instructions.
- Equivalent to fopen, with prep_instructions replacing mode. Prep instructions
are similar to the standard mode string, but with the follow equivalencies:
(grilled)	g = r
(seasoned)	s = w
(rare)		r = b
(continue)	c = a