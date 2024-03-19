### LINEAS QUE DEBEN EJECUTARSE SI NO SE CUENTA CON LAS LIBRERÍAS NECESARIAS###

# !pip install geopandas==0.12
# !pip3 install contextily
# !pip install -U geovoronoi[plotting]
# #To read/write data from Google Drive:
# #Reference: https://colab.research.google.com/notebooks/io.ipynb#scrollTo=u22w3BFiOveAå
# #from google.colab import drive
# #drive.mount('/content/drive')

# #df = pd.read_excel('/content/drive/My Drive/bomberos_oax.xlsx')
# municipios = gpd.read_file('/content/drive/My Drive/OAX.zip')

# # #When done,
# # drive.flush_and_unmount()
# # print('All changes made in this colab session should now be visible in Drive.')

import numpy as np
import geopandas as gpd
import pandas as pd
from pandas import DataFrame
import contextily as ctx
import matplotlib.pyplot as plt
from shapely.ops import cascaded_union
from geovoronoi.plotting import subplot_for_map, plot_voronoi_polys_with_points_in_area
from geovoronoi import voronoi_regions_from_coords, points_to_coords

#Leemos la información georeferenciada de los mercados. Primero como un dataframe y luego como un geodataframe
df = pd.read_excel('/content/drive/My Drive/bomberos_oax3.xlsx', index_col=0)
estaciones = gpd.GeoDataFrame(df, geometry=gpd.points_from_xy(df.long,df.lat)) ### Geodataframe
estaciones.head()

#Convertimos estos puntos en un sistema de coordenadas de referencia(CRS)
#WGS94 Latitude/Longitude: "EPSG:4326"

estaciones.crs = "EPSG:4326"

#importamos ahora los polígonos correspondientes a los municipios de México
municipios = gpd.read_file('/content/drive/My Drive/OAX2.zip')
# municipios

# #Tomamos ahora el polígono correspondiente al municipio de Oaxaca de Juárez
oax_jua = municipios[municipios['NOM_MUN'] == 'Oaxaca de JuÃ¡rez']
oax_jua

#Vamos a graficar estos datos.
municipio = oax_jua
fig, ax = plt.subplots(figsize=(12,10))
municipio.plot(ax=ax, color="orange")
estaciones.plot(ax=ax, markersize=30, color = "black")
ax.axis("off")
plt.axis('equal')
plt.show()

#Ajustamos la información al sistema de coordenadas de referencia (CRS)
municipio = municipio.to_crs(epsg=3359)
gdf_proj = estaciones.to_crs(municipio.crs)

#Convertimos estis datos al formato que puede ser utilizado por la biblioteca Geovoronoi
municipio_shape = cascaded_union(municipio.geometry)
coords = points_to_coords(gdf_proj.geometry)

#Calculamos ahora las regiones de Voronoi
poly_shapes, pts = voronoi_regions_from_coords(coords, municipio_shape)

#Graficamos el diagrama
fig, ax = subplot_for_map(figsize=(14.5,10))
plot_voronoi_polys_with_points_in_area(ax,municipio_shape,poly_shapes,coords,pts)
ax.set_title('Regiones de Voronoi para el municipio de Oaxaca de Juárez y sus supermercados')
plt.tight_layout()
plt.show()