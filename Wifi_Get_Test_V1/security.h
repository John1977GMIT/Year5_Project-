

/*

 * Copyright (c) 2015 ARM Limited. All rights reserved.

 * SPDX-License-Identifier: Apache-2.0

 * Licensed under the Apache License, Version 2.0 (the License); you may

 * not use this file except in compliance with the License.

 * You may obtain a copy of the License at

 *

 * http://www.apache.org/licenses/LICENSE-2.0

 *

 * Unless required by applicable law or agreed to in writing, software

 * distributed under the License is distributed on an AS IS BASIS, WITHOUT

 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

 * See the License for the specific language governing permissions and

 * limitations under the License.

 */

#ifndef __SECURITY_H__

#define __SECURITY_H__

 

#include <inttypes.h>

 

#define MBED_DOMAIN "5a6da97a-7f55-4e9e-aa2e-a0ef5a5cc1f3"

#define MBED_ENDPOINT_NAME "079a94b6-1f5a-48bc-aaec-94f0bc2ebe5d"

 

const uint8_t SERVER_CERT[] = "-----BEGIN CERTIFICATE-----\r\n"

"MIIBmDCCAT6gAwIBAgIEVUCA0jAKBggqhkjOPQQDAjBLMQswCQYDVQQGEwJGSTEN\r\n"

"MAsGA1UEBwwET3VsdTEMMAoGA1UECgwDQVJNMQwwCgYDVQQLDANJb1QxETAPBgNV\r\n"

"BAMMCEFSTSBtYmVkMB4XDTE1MDQyOTA2NTc0OFoXDTE4MDQyOTA2NTc0OFowSzEL\r\n"

"MAkGA1UEBhMCRkkxDTALBgNVBAcMBE91bHUxDDAKBgNVBAoMA0FSTTEMMAoGA1UE\r\n"

"CwwDSW9UMREwDwYDVQQDDAhBUk0gbWJlZDBZMBMGByqGSM49AgEGCCqGSM49AwEH\r\n"

"A0IABLuAyLSk0mA3awgFR5mw2RHth47tRUO44q/RdzFZnLsAsd18Esxd5LCpcT9w\r\n"

"0tvNfBv4xJxGw0wcYrPDDb8/rjujEDAOMAwGA1UdEwQFMAMBAf8wCgYIKoZIzj0E\r\n"

"AwIDSAAwRQIhAPAonEAkwixlJiyYRQQWpXtkMZax+VlEiS201BG0PpAzAiBh2RsD\r\n"

"NxLKWwf4O7D6JasGBYf9+ZLwl0iaRjTjytO+Kw==\r\n"

"-----END CERTIFICATE-----\r\n";

 

const uint8_t CERT[] = "-----BEGIN CERTIFICATE-----\r\n"

"MIIBzzCCAXOgAwIBAgIEFV92YTAMBggqhkjOPQQDAgUAMDkxCzAJBgNVBAYTAkZ\r\n"

"JMQwwCgYDVQQKDANBUk0xHDAaBgNVBAMME21iZWQtY29ubmVjdG9yLTIwMTgwHh\r\n"

"cNMTcwMTI2MTIwNTQxWhcNMTgxMjMxMDYwMDAwWjCBoTFSMFAGA1UEAxNJNWE2Z\r\n"

"GE5N2EtN2Y1NS00ZTllLWFhMmUtYTBlZjVhNWNjMWYzLzA3OWE5NGI2LTFmNWEt\r\n"

"NDhiYy1hYWVjLTk0ZjBiYzJlYmU1ZDEMMAoGA1UECxMDQVJNMRIwEAYDVQQKEwl\r\n"

"tYmVkIHVzZXIxDTALBgNVBAcTBE91bHUxDTALBgNVBAgTBE91bHUxCzAJBgNVBA\r\n"

"YTAkZJMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEuKf8+uTie38jacROpDn31\r\n"

"bPfoNHPYth1QwUo4wRvcZALqA12Y0z2Kl/SBngkqdqr26Z0pQsTnEh25CspstIt\r\n"

"azAMBggqhkjOPQQDAgUAA0gAMEUCIQDRAX966mm6f3aDTYZqbyf309dBkk7oMZX\r\n"

"dSI5rwix2EwIgWtZU6D5NSS0KkahYGZciGskdCnE3bNpmPHRJ3xdY464=\r\n"

"-----END CERTIFICATE-----\r\n";

 

const uint8_t KEY[] = "-----BEGIN PRIVATE KEY-----\r\n"

"MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgzw+5xH0IIhMoD4ji\r\n"

"ZZAGqQGNo1Hx7BGcPazAJs229V6hRANCAAS4p/z65OJ7fyNpxE6kOffVs9+g0c9i\r\n"

"2HVDBSjjBG9xkAuoDXZjTPYqX9IGeCSp2qvbpnSlCxOcSHbkKymy0i1r\r\n"

"-----END PRIVATE KEY-----\r\n";

 

#endif //__SECURITY_H__
