/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 University of California, Los Angeles
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Ilya Moiseenko <iliamo@cs.ucla.edu>
 */

#include "ndn_interestpacket.h"

namespace ns3
{
namespace NDNabstraction
{
    InterestPacket::InterestPacket(unsigned char *name, uint32_t size):Packet ((uint8_t const *)name,size)
    {
        maxNameLength = 10240;
    }
    
    uint32_t 
    InterestPacket::GetName(unsigned char *name)
    {
        //uint32_t Packet::CopyData (uint8_t *buffer, uint32_t size) const
        return CopyData((uint8_t*) name, maxNameLength); 
    }
    
    void 
    InterestPacket::AddTimeout(uint32_t milliseconds)
    {
        TimeoutHeader tHeader (milliseconds);
        AddHeader (tHeader);    
    }
    
    uint32_t
    InterestPacket::GetTimeout(void)
    {
        TimeoutHeader tHeader;
        PeekHeader(tHeader);
        return tHeader.GetValue();
    }
    
    void
    InterestPacket::RemoveTimeout(void)
    {
        TimeoutHeader tHeader;
        RemoveHeader(tHeader);
    }
    
    void 
    InterestPacket::AddNonce(uint32_t nonce)
    {
        NonceHeader tHeader (nonce);
        AddHeader (tHeader);    
    }
    
    uint32_t
    InterestPacket::GetNonce(void)
    {
        NonceHeader tHeader;
        PeekHeader(tHeader);
        return tHeader.GetValue();
    }
    
    void
    InterestPacket::RemoveNonce(void)
    {
        NonceHeader tHeader;
        RemoveHeader(tHeader);
    }
}
}
