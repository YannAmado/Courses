from fastapi import FastAPI, Path, Query
from typing import Optional
from pydantic import BaseModel


app = FastAPI()

class Item(BaseModel):
    name: str
    price: float
    brand: Optional[str] = None
    
class UpdateItem(BaseModel):
    name: Optional[str] = None
    price: Optional[float] = None
    brand: Optional[str] = None
       
inventory = {}

@app.get('/get-item/{item_id}')
def get_item(item_id: int = Path(None, description='The id of the item: ', gt=4)):
    return inventory[item_id]

@app.get('/get-by-name')
def get_item(name: str=Query(None, title='Name', description='Name of item')):
    for i_id in inventory:
        if inventory[i_id]['name'] == name:
            return inventory[i_id]
    return {'Data': 'Not Found'}


@app.put('/update-item/{item_id}')
def update_item(item_id: int, item: UpdateItem):
    if item_id not in inventory:
        return {'Error': 'Item ID does not exist'}
    
    if item.name != None:
        inventory[item_id].name = item.name
    if item.price != None:
        inventory[item_id].price = item.price
    if item.name != None:
        inventory[item_id].brand = item.brand
    
    

@app.delete('/delete-item')
def delete_item(item_id: int = Query(..., description='The ID of the item to delete')):
    if item_id not in inventory:
        return {'Error': 'ID does not exist'}
    
    del inventory[item_id]
    return {'Success': 'Item deleted!'}