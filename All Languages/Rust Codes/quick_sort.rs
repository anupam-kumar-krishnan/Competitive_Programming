

// quick sort
fn quick_sort(arr: &mut [i32]) {
    let len = arr.len();
    if len < 2 {
        return;
    }
    let pivot = arr[len / 2];
    let mut i = 0;
    let mut j = len - 1;
    while i <= j {
        while arr[i] < pivot {
            i += 1;
        }
        while arr[j] > pivot {
            j -= 1;
        }
        if i <= j {
            arr.swap(i, j);
            i += 1;
            j -= 1;
        }
    }
    if 0 < j {
        quick_sort(&mut arr[0..=j]);
    }
    if i < len - 1 {
        quick_sort(&mut arr[i..]);
    }
}

fn main() {
    let mut arr = [4, 2, 5, 3, 1];
    quick_sort(&mut arr);
    println!("{:?}", arr);
}
```
