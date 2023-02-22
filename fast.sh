#!/bin/bash
sudo cpufreq-set -g performance
cpufreq-info | grep current | tail -n 1

