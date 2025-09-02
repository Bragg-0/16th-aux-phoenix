import os
import re
import math
from mutagen.mp3 import MP3
from mutagen.oggvorbis import OggVorbis

def normalize_class_name(track_name):
    # Remplace tous les caractères spéciaux par un seul caractère de remplacement '_'
    normalized_name = re.sub(r'[^\w]+', '_', track_name)
    # Enlève les '_' en début et fin du nom
    return normalized_name.strip('_')

def get_audio_duration(file_path):
    try:
        if file_path.endswith('.ogg'):
            audio = OggVorbis(file_path)
        elif file_path.endswith('.mp3'):
            audio = MP3(file_path)
        else:
            print(f"Format audio non pris en charge : {file_path}")
            return 0

        # Arrondi vers le haut à la seconde supérieure
        return math.ceil(audio.info.length)
    except Exception as e:
        print(f"Erreur lors de la lecture de la durée de {file_path}: {str(e)}")
        return 0

# Chemin vers le répertoire racine contenant les dossiers de musiques
root_dir = os.path.dirname(os.path.abspath(__file__))

# Nom du fichier de sortie unique pour toutes les configurations
output_file = os.path.join(root_dir, 'CfgMusic.hpp')

# Ouvre le fichier de sortie en mode écriture
with open(output_file, 'w') as f_out:
    # Parcourt tous les sous-dossiers du répertoire racine
    for folder_name in os.listdir(root_dir):
        folder_path = os.path.join(root_dir, folder_name)

        if os.path.isdir(folder_path):
            # Parcourt le répertoire des musiques
            for root, dirs, files in os.walk(folder_path):
                for file in files:
                    # Vérifie si le fichier est une musique (formats .ogg ou .mp3)
                    if file.endswith('.ogg') or file.endswith('.mp3'):
                        # Récupère le nom du fichier sans l'extension
                        track_name = os.path.splitext(file)[0]
                        # Normalise le nom de la classe
                        class_name = normalize_class_name(track_name)
                        # Chemin absolu du fichier de musique
                        abs_path = os.path.join(root, file)
                        # Durée de la musique en secondes
                        duration = get_audio_duration(abs_path)
                        # Nom du dossier parent contenant le fichier audio
                        music_class = os.path.basename(os.path.dirname(abs_path))
                        # Crée le chemin relatif à partir du dossier 'Data/' et utilise la macro QPATHTOF()
                        data_index = abs_path.find('Data')
                        if data_index != -1:
                            relative_path = abs_path[data_index:].replace('\\', '/')
                            arma_path = f'QPATHTOF({relative_path})'
                        else:
                            arma_path = abs_path.replace('\\', '/')
                        # Écrit la configuration de la musique dans le fichier de sortie
                        f_out.write(f'    class GVAR({music_class}_{class_name}) {{\n')
                        f_out.write(f'        name = "{track_name}";\n')
                        f_out.write(f'        sound[] = {{{arma_path}, "db + 0", 1.0}};\n')
                        f_out.write(f'        duration = {duration};\n')
                        f_out.write(f'        musicClass = QGVAR({music_class});\n')
                        f_out.write(f'    }};\n')

# Encapsule le contenu dans la classe CfgMusic
with open(output_file, 'r') as f_in:
    content = f_in.read()
with open(output_file, 'w') as f_out:
    f_out.write('class CfgMusic {\n')
    f_out.write(content)
    f_out.write('};\n')
print("CfgMusic.hpp generated successfully!")
