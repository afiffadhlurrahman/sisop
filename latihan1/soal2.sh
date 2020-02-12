#!/bin/bash

crontab -e

* 0-15 * * * ls /home/afif/Downloads > /home/afif/log
* 18-23 * * * ls /home/afif/Downloads > /home/afif/log

