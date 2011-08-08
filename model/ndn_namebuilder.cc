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

#include "ndn_namebuilder.h"

namespace ns3 
{
namespace NDNabstraction
{
    NameBuilder::NameBuilder()
    {
        m_value = ccn_charbuf_create();
        ccn_name_init(m_value);
    }
    
    ccn_charbuf*
    NameBuilder::GetName()
    {
        return m_value;
    }
    
    void
    NameBuilder::AddComponent(string s)
    {
        
        ccn_name_append_str(m_value,s.c_str());
    }
}
}
