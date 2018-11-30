## Nginx HDA Bundle Snap Package
[![Get it from the Snap Store](https://snapcraft.io/static/images/badges/en/snap-store-white.svg)](https://snapcraft.io/nginx-hda-bundle)
>Snap package mainly created for use in distributions outside Ubuntu family. 

>Using [Nginx HDA Bundle PPA](https://launchpad.net/~hda-me/+archive/ubuntu/nginx-stable) is prefered in Ubuntu
### How to install
You can install with `sudo snap install nginx-hda-bundle --edge --devmode`
### Using nginx-hda-bundle snap
First time running nginx snap you need to create nginx configuration directy amd you can use `sudo snap run nginx-hda-bundle.first-run`
to do it.

`First-run` command would create nginx configuration directory in `/etc/nhb-snap/ location.

Other commands are `start`, `reload` and `stop`. To start, reload and stop nginx. And the same commands but with `-www` naming to start nginx under www-data user.
`-www` naming using `/etc/nhb-snap/nginx-www-data.conf` instead of `/etc/nhb-snap/nginx.conf`.

So overall all set of commands for nginx-hda-bundle snap looks like:

```bash
sudo snap run nginx-hda-bundle.first-run
sudo snap run nginx-hda-bundle.start
sudo snap run nginx-hda-bundle.start-www
sudo snap run nginx-hda-bundle.reload
sudo snap run nginx-hda-bundle.reload-www
sudo snap run nginx-hda-bundle.stop
sudo snap run nginx-hda-bundle.stop-www
```

### Donation

Consider making a donation, if you like what I doing.

I working remotely and income is unstable, so every little bit helps.

Also it would be nice if you provide, a note on `admin@hda.me` after making a donation with information what you like and what you want to improve. So, I would consider giving more time and support to particular project.

I also open to resonable work offers, especially if offer would be close to a field or project I work with.

#### E-money & Fiat

##### Yandex Money
[![Donation on Yandex Money](https://money.yandex.ru/i/shop/apple-touch-icon-72x72.png)](https://money.yandex.ru/to/410015241627045)
##### Advanced Cash
[Open](https://wallet.advcash.com/pages/transfer/wallet) and use `mmail@sent.com` in `Specify the recipient's wallet or e-mail` field
##### PayPal
[![Donation with PayPal](https://www.paypalobjects.com/webstatic/icon/pp72.png)](https://paypal.me/hdadonation)
##### Payeer
[![Donation with Payeer](https://payeer.com/bitrix/templates/difiz_account_new/img/logo-img.svg)](https://payeer.com/en/account/send/) use `P2865115` in `Account, e-mail or phone number` field

#### Cryptocurrency

##### Bitcoin
Address is `1N5czHaoSLukFSTq2ZJujaWGjkmBxv2dT9`
##### Musicoin 
Address is `0xf449f8c17a056e9bfbefe39637c38806246cb2c9`
##### Ethereum
Address is `0x23459a89eAc054bdAC1c13eB5cCb39F42574C26a`
##### Other 
I could provide you with some relatively cheap "hardware" donation options directly to my PO Box, if you prefer real gifts. Ask for details on `admin@hda.me`

### FAQ

> I don't have sudo. And why I need to start it under root?

You only need root, to be able to run under `www-data`, write to `/etc/nhb-snap/` directory and to bind to `80/433` ports. You could start without root using
`snap run nginx-hda-bundle.start`, but you need to make `/etc/nhb-snap/` writable first.

> How to install snap, in case I don't have snapd?

Check: https://docs.snapcraft.io/installing-snapd/6735

> Why no TLSv1.3 support in snap

Even in bionic (18.04) Ubuntu ships openssl 1.1.0, and I don't want to support openssl in Ubuntu on my own, since it needs critical security updates, which I'll not be able to provide as fast as Canonical security team.

Here is a thing, snaps are builded inside using xenial (Ubuntu 16.04) base, so if you think using snap would magically provide you always with super fresh sets of libs, this is not a true.

### Building snap package from scratch

Short: You need snapcraft, lxd for snapcraft cleanbuild and init and upgrade submodules

Longer:

```bash
git clone https://github.com/cryptofuture/nginx-hda-bundle-snap
cd nginx-hda-bundle-snap
git submodule init; git submodule update
cd nginx-hda-bundle
git submodule init; git submodule update
cd ..
./modules-folder-create.sh
snapcraft cleanbuild
sudo snap install *.snap --devmode --dangerous
```
