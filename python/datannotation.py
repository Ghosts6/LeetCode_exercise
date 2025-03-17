import requests
from bs4 import BeautifulSoup

def fetch_data_from_doc(url):
    """Fetches and parses data from the specified Google Doc."""
    response = requests.get(url)
    if response.status_code == 200:
        soup = BeautifulSoup(response.text, 'html.parser')
        
        table = soup.find('table')
        if not table:
            raise ValueError("No table found in the document.")
        
        grid_data = []
        for row in table.find_all('tr')[1:]:
            cells = row.find_all('td')
            if len(cells) == 3:
                try:
                    x = int(cells[0].text.strip())
                    char = cells[1].text.strip()
                    y = int(cells[2].text.strip())
                    grid_data.append({'x': x, 'char': char, 'y': y})
                except (ValueError, IndexError):
                    raise ValueError(f"Error parsing row: {row}. Please check the format.")
        return grid_data
    else:
        raise ValueError("Failed to fetch or access the Google Doc content.")

def build_and_print_grid(grid_data):
    """Builds and prints the grid of characters."""
    if not grid_data:
        print("No valid data found to build the grid.")
        return

    max_x = max(item['x'] for item in grid_data)
    max_y = max(item['y'] for item in grid_data)

    grid = [[' ' for _ in range(max_x + 1)] for _ in range(max_y + 1)]

    for item in grid_data:
        grid[item['y']][item['x']] = item['char']

    for row in grid:
        print(''.join(row))

if __name__ == "__main__":
    url = 'https://docs.google.com/document/d/e/2PACX-1vQGUck9HIFCyezsrBSnmENk5ieJuYwpt7YHYEzeNJkIb9OSDdx-ov2nRNReKQyey-cwJOoEKUhLmN9z/pub'
    
    try:
        grid_data = fetch_data_from_doc(url)
        build_and_print_grid(grid_data)
    except ValueError as e:
        print(f"Error: {e}")