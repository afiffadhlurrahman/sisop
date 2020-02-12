#!/bin/bash

crontab -e

* 0-14 * * * ls /home/afif/Downloads > /home/afif/log
* 19-23 * * * ls /home/afif/Downloads > /home/afif/log
