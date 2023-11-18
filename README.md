# syncBackup
<p>Front-end for rsync provides a fast and extraordinarily copying tool. It offers the most common options that control its behavior and permit very flexible specification of the set of files to be copied.</p>

<p>Rsync is widely used for backups and mirroring and as an improved copy command for everyday use and syncBackup put on your hands its power with a simple user interface.</p> 

<p><b>Features</b></p>
<ul>
  <li>It takes advantage of the delta-transfer algorithm, which reduces the amount of data sent over the network by sending only the differences between the source files and the existing files in the destination.</li>
  <li>It finds files that need to be transferred using a 'quick check' algorithm that looks for files that have changed in size or in last-modified time.</li>
  <li>Save your settings, source and destination directories in a file to keep different profiles.</li>
  <li>Exclude directories and/or files from your source to backup only the necessary data.</li>
  <li>Configure group, owner and permissions for the destination files to keep the source ones or to be changed based on the default system configuration.</li>
  <li>Recreate symlinks on the destination.</li>
  <li>Configure to keep or override files on destination with modified time newer than source files.</li>
  <li>Choose to keep the destination side an image of the source by deleting the files that aren't anymore in the source side.</li>
  <li>Choose to delete any file or directory on the destination side that is marked as excluded from the source to be backed up.</li>
  <li>Choose to skip creating files and directories that do not exist yet on the destination side.</li>
  <li>Choose to skip updating files that already exist on the destination regardless the modification time.</li>
  <li>Choose to copy directories from the source side recursively.</li>
  <li>Choose to limit the size of the files to be transfered to the destination side.</li>
  <li>There is an option to run the application in trial version to analyze the changes to be applied before running the real process.</li>
</ul>
## Availability
<p>[syncBackup from Flathub](https://flathub.org/apps/com.darhon.syncbackup)</p>
