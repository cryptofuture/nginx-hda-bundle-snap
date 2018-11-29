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

### FAQ

> I don't have sudo. And why I need to start it under root?

You only need root, to be able to run under `www-data`, write to `/etc/nhb-snap/` directory and to bind to `80/433` ports. You could start without root using
`snap run nginx-hda-bundle.start`, but you need to make `/etc/nhb-snap/` writable first.

> How to install snap, in case I don't have snapd?

Check: https://docs.snapcraft.io/installing-snapd/6735

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
