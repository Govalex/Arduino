/*
 Arduino_LCD_Menu Library
Copyright Dustin Andrews, David Andrews 2012 
Licensed under the follwing license:


Redistribution and use in source and binary forms, with or without modification, are permitted provided that the 
following conditions are met:
Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer. 
Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer 
in the documentation and/or other materials provided with the distribution. 
The name of the author may not be used to endorse or promote products derived from this software without specific prior written permission. 

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include "MenuIntHelper.h"

MenuIntHelper::MenuIntHelper( int iMin, int iMax, int iStart, int iStep ):
m_min( iMin), m_max( iMax ), m_curNum( iStart ), m_step( iStep)
{
}
int MenuIntHelper::numIncrease()
{
  //This function may have bugs when m_max is near the MAXINT limit 
  //but if your UI requires users to input MAXINT numbers, you have bigger problems.
  if( m_curNum + m_step < m_max )
  {
    m_curNum += m_step;
  }
  return m_curNum;
}
int MenuIntHelper::numDecrease()
{
  if( m_curNum - m_step >= m_min )
  {
    m_curNum -= m_step;
  }  
  return m_curNum;
}
int MenuIntHelper::getInt()
{
  return m_curNum;  
}

