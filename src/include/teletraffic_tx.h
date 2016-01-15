// Hi Emacs, this is -*- coding: utf-8; mode: c++; tab-width: 6; indent-tabs-mode: nil; c-basic-offset: 6 -*-
#ifndef TELETRAFFIC_TELETRAFFIC_RX_
#define TELETRAFFIC_TELETRAFFIC_RX_

#include <pthread.h>
#include <pcap/pcap.h>

#include <string>

namespace teletraffic {

      /**
       * Flow source properties
       */
      struct FlowSource {
            std::string source_interface;
            int speed_bytes_per_second;
            int protocol_id;
            int packet_size;
            char dest_mac[6];
      };
      
      
class TeletrafficRx {
public:

      
      /**
       * Constructor
       */
      TeletrafficRx(std::string eth_interface);
      
      /**
       * Destructor
       */
      TeletrafficRx();

      /**
       *
       */
      int Run();
      
      /**
       *
       */
      bool IsRunning();
      
      /**
       *
       */
      int Stop();

      /**
       */
      int sd();
      
private:
      pcap_t* pdev_;
      
      static
      void* ThreadFn(TeletrafficRx* obj);
      void* ThreadFn();
};

}

#endif // TELETRAFFIC_TELETRAFFIC_RX_

