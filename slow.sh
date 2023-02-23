#!/bin/bash
sudo cpufreq-set -g powersave
cpufreq-info | grep current | tail -n 1

