<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="es_ES">
<context>
    <name>AboutDialog</name>
    <message>
        <location filename="qml/AboutDialog.qml" line="+10"/>
        <location/>
        <source>About</source>
        <translation>Acerca</translation>
    </message>
</context>
<context>
    <name>CAbout</name>
    <message>
        <location filename="about.cpp" line="+18"/>
        <source>Backup and mirror your drives</source>
        <oldsource>Front-end of rsync for backup and mirroring purposes</oldsource>
        <translation>Respalda y replica tus discos</translation>
    </message>
    <message>
        <location line="+2"/>
        <source>It offers the most common options getting most of the power from rsync.</source>
        <translation>Ofrece las opciones más comunes de la herramienta rsync.</translation>
    </message>
    <message>
        <location line="+1"/>
        <source>It takes advantage of the delta-transfer algorithm, which reduces the amount of data sent over the network by sending only the differences between the source files and the existing files in the destination.</source>
        <translation>Usa las ventajas del algoritmo delta, que reduce el volumen de datos transmitidos en la red, enviando sólamente la diferencia entre los archivos fuente y los archivos existentes en el destino.</translation>
    </message>
    <message>
        <location line="+4"/>
        <source>It finds files that need to be transferred using a &apos;quick check&apos; algorithm that looks for files that have changed in size or in last-modified time.</source>
        <translation>Usa un algoritmo rápido para detectar los cambios tomando como referencia tamaño y fecha de modificación.</translation>
    </message>
    <message>
        <location line="+3"/>
        <source>Copyright</source>
        <translation>Derechos reservados</translation>
    </message>
    <message>
        <location line="+1"/>
        <source>Help &amp; Support</source>
        <translation>Ayuda y Soporte</translation>
    </message>
    <message>
        <location line="+2"/>
        <source>Privacy Policy</source>
        <translation>Politica de privacidad</translation>
    </message>
</context>
<context>
    <name>CBackend</name>
    <message>
        <location filename="backend.cpp" line="+142"/>
        <source>You have one of the following problems with the source/destination:</source>
        <translation>Hay uno de los siguientes problemas con la fuente/destino:</translation>
    </message>
    <message>
        <location line="+1"/>
        <source>The source or destination path is empty.</source>
        <translation>El directorio de la fuente o destino está vacío.</translation>
    </message>
    <message>
        <location line="+1"/>
        <source>One of the directories does not exist.</source>
        <translation>Uno de los directorios no existe.</translation>
    </message>
    <message>
        <location line="+1"/>
        <source>Source and destination are ssh remote.</source>
        <translation>La fuente y el destino son ssh remotos.</translation>
    </message>
    <message>
        <location line="+40"/>
        <source>-no-config-file-</source>
        <translation>-no-archivo-</translation>
    </message>
    <message>
        <location line="+176"/>
        <source>ERROR [%1] REPORTED BY THE BACKEND DURING EXCECUTION</source>
        <translation>ERROR [%1] REPORTADO DURANTE LA EXECUCIÓN</translation>
    </message>
    <message>
        <location line="+13"/>
        <source>BACKEND HAS CRASHED</source>
        <translation>PROBLEMAS CON LA HERRAMIENTA</translation>
    </message>
    <message>
        <location line="+5"/>
        <source>ERROR [%1] REPORTED BY THE BACKEND AT EXIT</source>
        <translation>ERROR [%1] REPORTADO POR LA HERRAMIENTA AL TERMINAR</translation>
    </message>
</context>
<context>
    <name>CommandlineDialog</name>
    <message>
        <location filename="qml/CommandlineDialog.qml" line="+11"/>
        <source>Command</source>
        <translation>Instrucción</translation>
    </message>
    <message>
        <location line="+35"/>
        <source>Copy</source>
        <translation>Copiar</translation>
    </message>
</context>
<context>
    <name>ExcIncHelpDialog</name>
    <message>
        <location filename="qml/ExcIncHelpDialog.qml" line="+8"/>
        <source>Guidelines to exclude or include files and directories</source>
        <translation>Guía para excluir o incluir archivos y directorios</translation>
    </message>
</context>
<context>
    <name>HelpDialog</name>
    <message>
        <location filename="qml/HelpDialog.qml" line="+8"/>
        <source>Help</source>
        <translation>Ayuda</translation>
    </message>
</context>
<context>
    <name>SSHDialog</name>
    <message>
        <location filename="qml/SSHDialog.qml" line="+12"/>
        <source>Address to remote server</source>
        <translation>Dirección del servidor remoto</translation>
    </message>
    <message>
        <location line="+35"/>
        <source>Port</source>
        <translation>Puerta</translation>
    </message>
    <message>
        <location line="+16"/>
        <source>Address</source>
        <translation>Dirección</translation>
    </message>
    <message>
        <location line="+5"/>
        <source>USER@HOST:PATH (username@200.150.150.11:backup_folder)</source>
        <translation>USUARIO@SERVIDOR:CAMINO (usuario@200.150.150.11:respaldo)</translation>
    </message>
</context>
<context>
    <name>initpage</name>
    <message>
        <location filename="qml/initpage.qml" line="+17"/>
        <source>Settings</source>
        <translation>Configuración</translation>
    </message>
    <message>
        <location line="+27"/>
        <source>Load</source>
        <translation>Cargar</translation>
    </message>
    <message>
        <location line="+8"/>
        <source>Save As</source>
        <translation>Salvar Como</translation>
    </message>
    <message>
        <location line="+8"/>
        <source>Reset</source>
        <translation>Resetear</translation>
    </message>
    <message>
        <location line="+34"/>
        <location line="+46"/>
        <source>Local</source>
        <translation>Local</translation>
    </message>
    <message>
        <location line="-38"/>
        <location line="+46"/>
        <source>Remote</source>
        <translation>Remoto</translation>
    </message>
    <message>
        <location line="-32"/>
        <source>SOURCE</source>
        <translation>FUENTE</translation>
    </message>
    <message>
        <location line="+46"/>
        <source>DESTINATION</source>
        <translation>DESTINO</translation>
    </message>
    <message>
        <location line="+34"/>
        <source>Run</source>
        <translation>Ejecutar</translation>
    </message>
    <message>
        <location line="+10"/>
        <source>Run the process as a trial without making changes</source>
        <translation>Ejecutar el proceso en modo de prueba sin hacer cambios</translation>
    </message>
    <message>
        <location line="+12"/>
        <source>Cancel</source>
        <translation>Cancelar</translation>
    </message>
    <message>
        <location line="+14"/>
        <source>WARNINGS in current configuration</source>
        <translation>ATENCIÓN con la configuración seleccionada</translation>
    </message>
    <message>
        <location line="+9"/>
        <source>Delete files in the destination, if they are no longer in the source</source>
        <translation>Borra archivos en el destino, si ya no existen en la fuente</translation>
    </message>
    <message>
        <location line="+5"/>
        <source>Delete files in the destination, if they are marked as excluded in the source</source>
        <translation>Borra archivos en el destino, si están marcados como excluidos en la fuente</translation>
    </message>
    <message>
        <location line="+5"/>
        <source>Replace files in the destination, even if modified time is newer than the source</source>
        <translation>Reemplaza archivos en el destino, incluso si han sido modificados post transferencia</translation>
    </message>
    <message>
        <location line="+27"/>
        <source>Open configuration file</source>
        <translation>Abrir el archivo de configuración</translation>
    </message>
    <message>
        <location line="+15"/>
        <source>The configuration file couldn&apos;t be opened, it may not be in the correct format</source>
        <translation>El archivo de configuración no se pudo abrir, el formato no es correcto</translation>
    </message>
    <message>
        <location line="+10"/>
        <source>Save configuration file</source>
        <translation>Guardar el archivo de configuración</translation>
    </message>
    <message>
        <location line="+15"/>
        <source>The configuration file couldn&apos;t be saved</source>
        <translation>El archivo de configuración no se pudo guardar</translation>
    </message>
    <message>
        <location line="+10"/>
        <source>Select folder for SOURCE</source>
        <translation>Seleccionar el directorio FUENTE</translation>
    </message>
    <message>
        <location line="+12"/>
        <source>Select folder for DESTINATION</source>
        <translation>Seleccionar el directorio DESTINO</translation>
    </message>
    <message>
        <location line="+36"/>
        <source>Information</source>
        <translation>Información</translation>
    </message>
</context>
<context>
    <name>mainwindow</name>
    <message>
        <location filename="qml/mainwindow.qml" line="+12"/>
        <source>&amp;Menu</source>
        <translation>&amp;Menu</translation>
    </message>
    <message>
        <location line="+2"/>
        <source>&amp;Command</source>
        <translation>&amp;Instrucción</translation>
    </message>
    <message>
        <location line="+8"/>
        <source>&amp;Help</source>
        <translation>&amp;Ayuda</translation>
    </message>
    <message>
        <location line="+5"/>
        <source>&amp;About</source>
        <translation>&amp;Acerca</translation>
    </message>
    <message>
        <location line="+6"/>
        <source>&amp;Quit</source>
        <translation>&amp;Salir</translation>
    </message>
    <message>
        <location line="+23"/>
        <source>Alert</source>
        <translation>Alerta</translation>
    </message>
    <message>
        <location line="+2"/>
        <source>The process is running, do you still want to close the application?</source>
        <translation>El proceso está corriendo, esta seguro de cerrar la aplicación?</translation>
    </message>
</context>
<context>
    <name>settings</name>
    <message>
        <location filename="qml/settings.qml" line="+14"/>
        <source>Back</source>
        <translation>Atrás</translation>
    </message>
    <message>
        <location line="+29"/>
        <source>Configure files in destination</source>
        <translation>Configuración de archivos en el destino</translation>
    </message>
    <message>
        <location line="+6"/>
        <source>Set the &lt;u&gt;group&lt;/u&gt; of the destination file to be the same as the source</source>
        <translation>Configura el campo &lt;u&gt;grupo&lt;/u&gt; en el destino, igual que en la fuente</translation>
    </message>
    <message>
        <location line="+6"/>
        <source>Set the &lt;u&gt;owner&lt;/u&gt; of the destination file to be the same as the source</source>
        <translation>Configura el campo &lt;u&gt;usuario&lt;/u&gt; en el destino, igual que en la fuente</translation>
    </message>
    <message>
        <location line="+6"/>
        <source>Set the &lt;u&gt;permission&lt;/u&gt; of the destination file to be the same as the source</source>
        <translation>Configura los &lt;u&gt;permisos&lt;/u&gt; en el destino, igual que en la fuente</translation>
    </message>
    <message>
        <location line="+6"/>
        <source>When a &lt;u&gt;symlink&lt;/u&gt; is encountered, recreates the symlink in the destination</source>
        <translation>Cuando se encuentra un &lt;u&gt;enlace&lt;/u&gt;, recrear el enlace también en la fuente</translation>
    </message>
    <message>
        <location line="+12"/>
        <source>Configure actions in destination</source>
        <translation>Configuración de acciones en el destino</translation>
    </message>
    <message>
        <location line="+6"/>
        <source>Delete files in the destination, if they are no longer in the source</source>
        <translation>Borrar archivos en el destino, si ya no existen en la fuente</translation>
    </message>
    <message>
        <location line="+6"/>
        <source>Delete files in the destination, if they are marked as excluded in the source</source>
        <translation>Borra archivos en el destino, si están marcados como excluidos en la fuente</translation>
    </message>
    <message>
        <location line="+6"/>
        <source>Only update existing files in the destination. Do not transfer new files</source>
        <translation>Sólamente actualizar archivos existentes en el destino. No transferir nada nuevo</translation>
    </message>
    <message>
        <location line="+6"/>
        <source>Do not replace files in the destination, if they already exist</source>
        <translation>No reemplazar archivos en el destino si ya existen</translation>
    </message>
    <message>
        <location line="+6"/>
        <source>Do not replace files in the destination, when modified time is newer than the source</source>
        <translation>No reemplazar archivos en el destino, si han sido modificados después de transferirlos</translation>
    </message>
    <message>
        <location line="+13"/>
        <source>Configure actions in source</source>
        <translation>Configuración de acciones en la fuente</translation>
    </message>
    <message>
        <location line="+6"/>
        <source>Copy directories recursively</source>
        <translation>Copia directorios recursivamente</translation>
    </message>
    <message>
        <location line="+7"/>
        <source>Avoid transferring files larger than</source>
        <translation>No transferir archivos mayores que</translation>
    </message>
    <message>
        <location line="+31"/>
        <source>List of files and directories to be excluded and included</source>
        <translation>Lista de archivos y directorios para ser excluidos o incluidos</translation>
    </message>
    <message>
        <location line="+16"/>
        <source>Compose PATH to insert in Excluded or Included</source>
        <translation>Crear el camino para insertar en Excluidos o Incluidos</translation>
    </message>
    <message>
        <location line="+3"/>
        <source>Help</source>
        <translation>Ayuda</translation>
    </message>
    <message>
        <location line="+16"/>
        <source>EXCLUDED</source>
        <translation>EXCLUIDOS</translation>
    </message>
    <message>
        <location line="+6"/>
        <location line="+51"/>
        <source>Insert</source>
        <translation>Insertar</translation>
    </message>
    <message>
        <location line="-40"/>
        <location line="+51"/>
        <source>Delete</source>
        <translation>Borrar</translation>
    </message>
    <message>
        <location line="-17"/>
        <source>INCLUDED</source>
        <translation>INCLUIDOS</translation>
    </message>
</context>
</TS>
