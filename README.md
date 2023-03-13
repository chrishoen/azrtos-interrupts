# azrtos-port
### azrtos port test progams, C++, ccs and vstudio

This is a temporary repo for porting azrtos. It attempts to combine the current azrtos 6.2.0
and the current NexGenB daVinci code base.

1) it started with original versions of threadx, filex, netxduo, and usbx 6.2.0
2) several changes that were maded to the original davinci code base in 2018 were
   ported over. these changes were found by examining the git history in the
   Luminex git repo.

change mutex attribute to TX_INHERIT, priority inversion feature dkb 10/23/2018
60860d3c0598fab8cba8f6930ed5131a9a95d067

make DHCP work the same way as Diamante dkb 10/23/2018
e1628c43f324cc0a2c94f0df4fd968eed1562e40

Changes to allow Console mode to work on PC with VisualStudio km 9/5/2018
a20f791200f75030ded50b71cd0bf69e180ef46e

these can be found by searching for the string "davinci commit" without the quotes.

