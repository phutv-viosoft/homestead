/**
 * @file cx.h class definition wrapping Cx
 *
 * Project Clearwater - IMS in the Cloud
 * Copyright (C) 2013  Metaswitch Networks Ltd
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version, along with the "Special Exception" for use of
 * the program along with SSL, set forth below. This program is distributed
 * in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details. You should have received a copy of the GNU General Public
 * License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * The author can be reached by email at clearwater@metaswitch.com or by
 * post at Metaswitch Networks Ltd, 100 Church St, Enfield EN2 6BQ, UK
 *
 * Special Exception
 * Metaswitch Networks Ltd  grants you permission to copy, modify,
 * propagate, and distribute a work formed by combining OpenSSL with The
 * Software, or a work derivative of such a combination, even if such
 * copying, modification, propagation, or distribution would otherwise
 * violate the terms of the GPL. You must comply with the GPL in all
 * respects for all of the code used other than OpenSSL.
 * "OpenSSL" means OpenSSL toolkit software distributed by the OpenSSL
 * Project and licensed under the OpenSSL Licenses, or a work based on such
 * software and licensed under the OpenSSL Licenses.
 * "OpenSSL Licenses" means the OpenSSL License and Original SSLeay License
 * under which the OpenSSL Project distributes the OpenSSL toolkit software,
 * as those licenses appear in the file LICENSE-OPENSSL.
 */

#ifndef CX_H__
#define CX_H__

#include "diameterstack.h"

namespace Cx
{
class Dictionary : public Diameter::Dictionary
{
public:
  Dictionary();
  Diameter::Dictionary::Vendor TGPP;
  Diameter::Dictionary::Application CX;
  Diameter::Dictionary::Message MULTIMEDIA_AUTH_REQUEST;
  Diameter::Dictionary::Message MULTIMEDIA_AUTH_ANSWER;
  Diameter::Dictionary::AVP SUPPORTED_FEATURES;
  Diameter::Dictionary::AVP PUBLIC_IDENTITY;
  Diameter::Dictionary::AVP SIP_AUTH_DATA_ITEM;
  Diameter::Dictionary::AVP SIP_AUTH_SCHEME;
  Diameter::Dictionary::AVP SIP_NUMBER_AUTH_ITEMS;
  Diameter::Dictionary::AVP SERVER_NAME;
  Diameter::Dictionary::AVP SIP_DIGEST_AUTHENTICATE;
  Diameter::Dictionary::AVP DIGEST_HA1;
  Diameter::Dictionary::AVP DIGEST_REALM;
};

class MultimediaAuthRequest : public Diameter::Message
{
public:
  MultimediaAuthRequest(const Dictionary* dict,
                        const std::string& dest_realm,
                        const std::string& dest_host,
                        const std::string& impi,
                        const std::string& impu,
                        const std::string& server_name,
                        const std::string& sip_auth_scheme);
  inline MultimediaAuthRequest(Diameter::Message& msg) : Diameter::Message(msg) {};

  std::string impi() const;
  std::string impu() const;
  std::string server_name() const;
  std::string sip_auth_scheme() const;
};

class MultimediaAuthAnswer : public Diameter::Message
{
public:
  MultimediaAuthAnswer(const Dictionary* dict,
                       int result_code);
  inline MultimediaAuthAnswer(Diameter::Message& msg) : Diameter::Message(msg) {};

  int result_code() const;
  std::string sip_auth_scheme() const;
  std::string digest_ha1() const;
};
};

#endif