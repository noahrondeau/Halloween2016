
#include <Thread.h>
#include <ThreadController.h>

#include <math.h>


enum Pin_t
{
  p2 = 2,
  p3,
  p4,
  p5,
  p6,
  p7,
  p8,
  p9,
  p10,
  p11,
  p12,
  p13
};

template< int pin > struct Functor_t
{
  Functor_t( void (&func)() )
  {
    m_func = func;
  }
  void operator()()
  {
    m_func();
  }

  void (&m_func)();
};

// LED toggle callback

template<int pin> void ledToggle()
{
  digitalWrite(pin, !digitalRead(pin));
}

// LED pulse callbacks

template<int pin, typename T, T functor> void ledPWM()
{
  functor();
}

template<int pin> void doSinusoid()
{
  static int counter = 0;
}

ThreadController ledController = ThreadController();

void setup()
{

  // Set pinmode for all digital out pins
  for( int i = 2; i <= 13; i++ )
  {
    pinMode( i, OUTPUT );
    digitalWrite(i, LOW);
  }

  // LED THREADS
  
  // Turns stays on for one second, off for one second
  Thread p2Thread = Thread();
  p2Thread.setInterval(1000);
  p2Thread.onRun(ledToggle<p2>);

  // COnfigure led controller
  ledController.add(&p2Thread);
}
  
void loop()
{
  ledController.run();
}
