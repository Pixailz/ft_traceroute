# ft_traceroute

1. IBM Man about the traceroute cmmand
   [IBM_MAN_TRACEROUTE](https://www.ibm.com/docs/fr/power8?topic=commands-traceroute-command)

## TCPDUMP FILTER

```sh
# don't resolve ip addresses
sudo tcpdump -n

# filter on ip.identification == 0x01a4 (420)
sudo tcpdump ip[4:2] == 0x01a4

# filter on ip.dst_addr == 0x08080808
sudo tcpdump ip[16:4] == 0x08080808

# filter on ip.dst_addr == 0x08080808
sudo tcpdump ip[16:4] == 0x08080808

# filter on icmp
sudo tcpdump icmp

# filter by interface
sudo tcpdump -i wlan0

# show raw packet in hex
sudo tcpdump -x

# all together
sudo tcpdump -xni wlan0 ip[4:2] == 0x01a4 or icmp
```

## TODO

1. fix flag at the end pop `unknown host`
1. fix getting weird result in `ft_i4toh`
1. fix header of stat when `-r` is not present
1. sort ip on prob, so different ip could be spotted more easily
