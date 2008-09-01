#ifndef __TIMER_H__
#define __TIMER_H__

#include "SDL/SDL_types.h"
#include "SDL/SDL_timer.h"

#include <tools/singleton.h>

class Timer:public Singleton <Timer>
{
  private:
    bool m_paused;
    Uint32 m_begin_time;
    Uint32 m_pause_begin_time;
    Uint32 m_total_pause_time;

    friend class Singleton <Timer>;

    void Constructor (void);

    Timer ()
    {
	Constructor ();
    }

  public:

    inline void Reset (void)
    {
	Constructor ();
	m_begin_time = SDL_GetTicks ();
    }

    void Pause (void);

    void Continue (void);

    inline Uint32 Read (void) const
    {
	return (m_paused) ?
	    (m_pause_begin_time - m_begin_time - m_total_pause_time) :
	    (SDL_GetTicks () - m_begin_time - m_total_pause_time);
    }

    inline Uint32 ReadSec (void) const
    {
	return Read () / 1000;
    }
};

#endif /*      __TIMER_H__     */
