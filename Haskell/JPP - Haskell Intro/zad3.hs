fibonacci :: Int -> Integer
fibonacci n
  | n == 0 = 0
  | n == 1 = 1
  | otherwise = fibonacci (n - 1) + fibonacci (n - 2)

main :: IO ()
main = do
  let n = 10
  let result = fibonacci n
  print $ "In Fib:" ++ show n
  print $ "Numer: " ++ show n ++ " - wynosi " ++ show result
